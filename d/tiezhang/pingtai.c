// Room: /d/tiezhang/pingtai.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>;
inherit ROOM;
string look_ditu();
void create()
{
	set("short", BLU"ɽ��ƽ̨"NOR);
	set("long", @LONG
������ɽ���һ��ƽ�ء�ɽ�������￪ʼ��֧����������ǰ������
���������Ƶ�ɽ�壬�����˵���ָ��������ɽ��֮���ɴ˶��á������
ͬ����ɽ����Ĵָ��֮��ΰ��ʳָ��֮�վ�����ָ��֮���ʣ�������֮��
����Сָ��֮�������������ɫ������ʤ������ƽ̨һ��Ĵ�ʯ�ϣ�����
һ����ͼ(ditu)��
LONG	);
	set("item_desc", ([ 
		"ditu" : (: look_ditu :),
	]));
	set("exits", ([ 
		"westup"    : __DIR__"shanlu5",
		"northeast" : __DIR__"shangu1",
		"eastup"    : __DIR__"sslu1",
		"southdown" : __DIR__"shanlu4",
		"northwest" : __DIR__"hclu1",
		"northup"   : __DIR__"shanlu6",
	]));
	set("objects", ([ 
		__DIR__"npc/huiyi" : 3,
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2040);
	set("coor/y", -1910);
	set("coor/z", 50);
	setup();
}

string look_ditu()
{
	return
	"\n"
	"############################\n"
	"#          ��ָ��          #\n"
	"#            ||            #\n"
	"#    ������  ||  ʳָ��    #\n"
	"#         \\ || //         #\n"
	"#          \\||//          #\n"
	"# Сָ��====ƽ̨====Ĵָ�� #\n"
	"############################\n";
	"\n";
}
