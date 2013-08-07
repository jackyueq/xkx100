// Room: /d/5lt/msoffice.c

inherit ROOM;

void create()
{
	set("short", "���鴦");
	set("long", @LONG
�����ǵ���̨�����鴦���������۵ذ������Ŵ��İ칫��������
����������λ���顣��ְλ��С������̨���СС����������϶���
���ǰѳ֡�������̨���칫�ҡ�
LONG);
	set("outdoors", "5lt");
	set("exits", ([
		"up"     : __DIR__"yanboting",
		"down"   : __DIR__"dating",
		"east"   : __DIR__"tzoffice",
	]));
        set("objects", ([
		__DIR__"npc/xueyuan"   : 1,
	        __DIR__"npc/singleblue": 1,
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("coor/x", -185);
	set("coor/y", 30);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
