/*
 *    Copyright 2013, 2015, 2016 Kai Pastor
 *
 *    This file is part of OpenOrienteering.
 *
 *    OpenOrienteering is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    OpenOrienteering is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with OpenOrienteering.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OPENORIENTEERING_OCD_TYPES_V11_H
#define OPENORIENTEERING_OCD_TYPES_V11_H

#include "ocd_types.h"
#include "ocd_types_v10.h"

namespace Ocd
{
	
#pragma pack(push, 1)
	
	using FileHeaderV11 = FileHeaderV10;
	
	struct BaseSymbolV11
	{
		typedef quint32 IndexEntryType;
		
		typedef BaseSymbolV11 BaseSymbol;
		static const int symbol_number_factor = 1000;
		
		quint32 size;
		quint32 number;
		quint8  type;
		quint8  flags;
		quint8  selected;
		quint8  status;
		quint8  tool;
		quint8  cs_mode;
		quint8  cs_type;
		quint8  cd_flags;
		qint32  extent;
		quint32 file_pos;
		quint8  RESERVED_MEMBER[2];
		quint16 num_colors;
		quint16 colors[14];
		QChar   description[64];
		quint8  icon_bits[484];
		quint16 group[64];
		
		enum StatusFlag
		{
			StatusNormal    = 0,
			StatusProtected = 1,
			StatusHidden    = 2
		};
	};
	
	using PointSymbolElementV11 = PointSymbolElementV10;
	
	struct PointSymbolV11
	{
		typedef BaseSymbolV11 BaseSymbol;
		typedef PointSymbolElementV11 Element;
		
		BaseSymbol base;
		
		quint16 data_size;
		quint16 RESERVED_MEMBER;
		Element begin_of_elements[1];
	};
	
	struct LineSymbolV11
	{
		typedef BaseSymbolV11 BaseSymbol;
		typedef PointSymbolElementV11 Element;
		
		BaseSymbol base;
		
		quint16 line_color;
		quint16 line_width;
		quint16 line_style;
		qint16  dist_from_start;
		qint16  dist_from_end;
		qint16  main_length;
		qint16  end_length;
		qint16  main_gap;
		qint16  sec_gap;
		qint16  end_gap;
		qint16  min_sym;
		qint16  num_prim_sym;
		qint16  prim_sym_dist;
		quint16 double_mode;
		quint16 double_flags;
		quint16 double_color;
		quint16 double_left_color;
		quint16 double_right_color;
		qint16  double_width;
		qint16  double_left_width;
		qint16  double_right_width;
		qint16  double_length;
		qint16  double_gap;
		quint16 double_background_color;
		quint16 RESERVED_MEMBER[2];
		quint16 dec_mode;
		quint16 dec_last;
		quint16 RESERVED_MEMBER;
		quint16 framing_color;
		qint16  framing_width;
		quint16 framing_style;
		quint16 primary_data_size;
		quint16 secondary_data_size;
		quint16 corner_data_size;
		quint16 start_data_size;
		quint16 end_data_size;
		quint8  active_symbols;
		quint8  RESERVED_MEMBER;
		
		Element begin_of_elements[1];
		
		enum LineStyleFlag
		{
			BevelJoin_FlatCap    = 0,
			RoundJoin_RoundCap   = 1,
			BevelJoin_PointedCap = 2,
			RoundJoin_PointedCap = 3,
			MiterJoin_FlatCap    = 4,
			MiterJoin_PointedCap = 6
		};
		
		enum DoubleLineFlag
		{
			DoubleFillColorOn       = 1,
			DoubleBackgroundColorOn = 2
		};
	};
	
	struct AreaSymbolV11
	{
		typedef BaseSymbolV11 BaseSymbol;
		typedef PointSymbolElementV11 Element;
		
		BaseSymbol base;
		
		quint32 border_symbol;
		quint16 fill_color;
		quint16 hatch_mode;
		quint16 hatch_color;
		quint16 hatch_line_width;
		quint16 hatch_dist;
		qint16  hatch_angle_1;
		qint16  hatch_angle_2;
		quint8  fill_on;
		quint8  border_on;
		quint16 structure_mode;
		quint16 structure_width;
		quint16 structure_height;
		qint16  structure_angle;
		quint16 RESERVED_MEMBER;
		quint16 data_size;
		
		Element begin_of_elements[1];
		
		enum HatchMode
		{
			HatchNone   = 0,
			HatchSingle = 1,
			HatchCross  = 2
		};
		
		enum StructureMode
		{
			StructureNone = 0,
			StructureAlignedRows = 1,
			StructureShiftedRows = 2
		};
	};
	
	struct TextSymbolV11
	{
		typedef BaseSymbolV11 BaseSymbol;
		
		BaseSymbol base;
		
		Utf8PascalString<31> font_name;
		quint16 font_color;
		quint16 font_size;
		quint16 font_weight;
		quint8  font_italic;
		quint8  RESERVED_MEMBER;
		quint16 char_spacing;
		quint16 word_spacing;
		quint16 alignment;
		quint16 line_spacing;
		qint16  para_spacing;
		quint16 indent_first_line;
		quint16 indent_other_lines;
		quint16 num_tabs;
		quint32 tab_pos[32];
		quint16 line_below_on;
		quint16 line_below_color;
		quint16 line_below_width;
		quint16 line_below_offset;
		quint16 RESERVED_MEMBER;
		quint8  framing_mode;
		quint8  framing_line_style;
		quint8  point_symbol_on;
		quint32 point_symbol_number;
		Utf8PascalString<18> RESERVED_MEMBER;
		quint16 framing_border_left;
		quint16 framing_border_bottom;
		quint16 framing_border_right;
		quint16 framing_border_top;
		quint16 framing_color;
		quint16 framing_line_width;
		quint16 RESERVED_MEMBER[2];
		quint16 framing_offset_x;
		quint16 framing_offset_y;
		
		enum TextAlignment
		{
			HAlignMask      = 0x03,
			HAlignLeft      = 0x00,
			HAlignCenter    = 0x01,
			HAlignRight     = 0x02,
			HAlignJustified = 0x03,
			VAlignMask      = 0x0c, /// \since V10
			VAlignBottom    = 0x00, /// \since V10
			VAlignMiddle    = 0x04, /// \since V10
			VAlignTop       = 0x08  /// \since V10
		};
	};
	
	struct LineTextSymbolV11
	{
		typedef BaseSymbolV11 BaseSymbol;
		
		BaseSymbol base;
		
		Utf8PascalString<31> font_name;
		quint16 font_color;
		quint16 font_size;
		quint16 font_weight;
		quint8  font_italic;
		quint8  RESERVED_MEMBER;
		quint16 char_spacing;
		quint16 word_spacing;
		quint16 alignment;
		quint8  framing_mode;
		quint8  framing_line_style_V10; /// \since V10
		Utf8PascalString<31> RESERVED_MEMBER;
		quint16 framing_color;
		quint16 framing_line_width;
		quint16 RESERVED_MEMBER[2];
		quint16 framing_offset_x;
		quint16 framing_offset_y;
		
		enum TextAlignment
		{
			HAlignMask      = 0x03,
			HAlignLeft      = 0x00,
			HAlignCenter    = 0x01,
			HAlignRight     = 0x02,
			HAlignAllLine   = 0x03,
			VAlignMask      = 0x0c, /// \since V10
			VAlignBottom    = 0x00, /// \since V10
			VAlignMiddle    = 0x04, /// \since V10
			VAlignTop       = 0x08  /// \since V10
		};
	};
	
	struct RectangleSymbolV11
	{
		typedef BaseSymbolV11 BaseSymbol;
		
		BaseSymbol base;
		
		quint16 line_color;
		quint16 line_width;
		quint16 corner_radius;
		quint16 grid_flags;
		quint16 cell_width;
		quint16 cell_height;
		quint16 RESERVED_MEMBER[2];
		quint16 unnumbered_cells;
		Utf8PascalString<3> unnumbered_text;
		quint16 line_style;
		Utf8PascalString<31> RESERVED_MEMBER;
		quint16 RESERVED_MEMBER;
		quint16 font_size_V10;      /// \since V10
		quint16 RESERVED_MEMBER[4];
	};
	
	using ObjectIndexEntryV11 = ObjectIndexEntryV10;
	
	using ObjectV11 = ObjectV10;
	
#pragma pack(pop)
	
	/** OCD file format version 11 trait. */
	struct FormatV11
	{
		static constexpr int version() { return 11; }
		
		typedef FileHeaderV11 FileHeader;
		
		typedef BaseSymbolV11 BaseSymbol;
		typedef PointSymbolV11 PointSymbol;
		typedef LineSymbolV11 LineSymbol;
		typedef AreaSymbolV11 AreaSymbol;
		typedef TextSymbolV11 TextSymbol;
		typedef LineTextSymbolV11 LineTextSymbol;
		typedef RectangleSymbolV11 RectangleSymbol;
		
		typedef ObjectV11 Object;
		
		typedef Utf8Encoding Encoding;
		
		enum SymbolType
		{
			TypePoint     = 1,
			TypeLine      = 2,
			TypeArea      = 3,
			TypeText      = 4,
			TypeLineText  = 6,
			TypeRectangle = 7
		};
	};
}

#endif // OPENORIENTEERING_OCD_TYPES_V11_H