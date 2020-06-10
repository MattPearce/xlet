using System;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;

namespace ImageConverter
{
    class Program
    {
        static int GetRGB565(int r, int g, int b)
        {
            return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Xlet Image Converter");

            if (args.Count() != 2 || !Directory.Exists(args[0]) || !Directory.Exists(args[1]))
            {
                Console.WriteLine("Usage: ImageConverter.exe [input_directory] [output_directory]");
            }

            var files = Directory.GetFiles(args[0])
                .Where(f => f.EndsWith(".png"))
                .ToList();

            foreach(var file in files)
            {
                var result = new StringBuilder();

                var name = file.Split(@"\").Last().Split(".").First();

                result.AppendLine("#pragma once");
                result.AppendLine();
                result.AppendLine("#include \"Icon.h\"");
                result.AppendLine();
                result.AppendLine("namespace Xlet");
                result.AppendLine("{");
                result.AppendLine("\tnamespace Icons");
                result.AppendLine("\t{");
                result.AppendLine("\t\tconst uint16_t icon_data_" + name.ToLower() + "[] = {");

                using (FileStream pngStream = new FileStream(file, FileMode.Open, FileAccess.Read))
                {
                    using (var image = new Bitmap(pngStream))
                    {
                        for (int y = 0; y < image.Height; ++y)
                        {
                            result.Append("\t\t\t");

                            for(int x = 0; x < image.Width; ++x)
                            {
                                var color = image.GetPixel(x, y);

                                result.Append(GetRGB565(color.R, color.G, color.B));

                                // Don't add a comma for the last value
                                if (!(x == image.Width - 1 && y == image.Height - 1))
                                {
                                    result.Append(", ");
                                }
                            }

                            result.AppendLine();
                        }

                        result.AppendLine("\t\t};");
                        result.AppendLine();
                        result.AppendLine("\t\tclass " + name + " : public Icon");
                        result.AppendLine("\t\t{");
                        result.AppendLine("\t\tpublic:");
                        result.AppendLine("\t\t\tconst uint16_t* GetImage() const");
                        result.AppendLine("\t\t\t{");
                        result.AppendLine("\t\t\t\treturn icon_data_" + name.ToLower() + ";");
                        result.AppendLine("\t\t\t}");
                        result.AppendLine();
                        result.AppendLine("\t\t\tint GetWidth() const");
                        result.AppendLine("\t\t\t{");
                        result.AppendLine("\t\t\t\treturn " + image.Width + ";");
                        result.AppendLine("\t\t\t}");
                        result.AppendLine();
                        result.AppendLine("\t\t\tint GetHeight() const");
                        result.AppendLine("\t\t\t{");
                        result.AppendLine("\t\t\t\treturn " + image.Height + ";");
                        result.AppendLine("\t\t\t}");
                        result.AppendLine("\t\t};");
                        result.AppendLine("\t}");
                        result.AppendLine("}");
                        result.AppendLine();
                    }
                }

                var outputFile = file.Replace(args[0], args[1]).Replace(".png", ".h");

                System.IO.File.WriteAllText(outputFile, result.ToString());


                Console.WriteLine("Converted " + file + " to " + outputFile);
            }

            Console.WriteLine();

            Console.WriteLine("Successfully converted " + files.Count + " images");
        }
    }
}
