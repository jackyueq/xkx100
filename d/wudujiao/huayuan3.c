// Room: /d/wudujiao/huayuan3.c

inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
�����Ǹ���԰��һ���ļ��������Ÿ�������Ļ��ݣ��������·����߲�
���޵Ĺ�ԡ���԰��һƬ���ţ���������һֻ�۷��������衣�Ա���һ��
Сͤ�ӡ�
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"huating3",
                "south" : __DIR__"huayuan1",
        ]));

	set("coor/x", -44900);
	set("coor/y", -81040);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}