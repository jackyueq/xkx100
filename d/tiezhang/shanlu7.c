// Room: /d/tiezhang/shanlu7.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;

string look_dazi();

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ����᫵�ɽ·�ϣ�����ɽ����������ݹ������м�һ����
��С·������һ����ǿ��ȥ��ǰ����һƬï�ܵ����֡�·�Ե�ʯ���Ͽ�
�ż�������(dazi)��
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"sslin1",
		"southdown" : __DIR__"shanlu6",
	]));
	set("item_desc",([
		"dazi" : (: look_dazi :),
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2040);
	set("coor/y", -1890);
	set("coor/z", 70);
	setup();
}

string look_dazi()
{
        return
        "\n"
"    ���ư��ص�    \n"    
        "\n"
 "    ������----    \n"
RED"              ����    \n"NOR
        "\n";
}