// Room: /city/zxlpath.c
// YZC 1995/12/04 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "����¥����");
	set("long", @LONG
��������¥���ã������������˿ͺ�����С�������������������
�̶��ĺ����������������������������������ַǷ����������������
ǰ�����Ž��ĸ��ո����֣�����ʳ��
    ÿ��ʮ�����������������������������������С���ʱ����
���Ƽ���ֱ��һ�Ըߵ͡�������뷢�ƣ��ɲ�Ҫ���Ŷ��
LONG);
	set("exits", ([
		"east"   : __DIR__"meigui",
		"north"  : __DIR__"furong",
		"south"  : __DIR__"mudan",
		"west"   : __DIR__"zuixianlou2",
	]));
        set("no_fight","1");
	set("no_beg", 1);
	set("coor/x", 21);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
	SHOP_DIR"situheng"->come_here();
}
