// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "�෿");
	set("long", @LONG
��������¼��϶��·���ƽʱ��������ס������������
�¼���������������ͷ�Ե��������ƽʱһ�㶼û�ڼң���
�����������ȥ�ˡ�
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"zoulang1",
	]));
	set("objects", ([
		__DIR__"npc/wenfangwu" : 1,
	]));
	set("coor/x", 1590);
	set("coor/y", -1940);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}