// damen.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
        set("short", "ʯ�Ҵ���");
        set("long", @LONG
�����Ҷ���ͻȻ֮�䣬������һ���������Բ�ԭ���Ǹ��Ż���
�Ż��ĺ�������һ��ͭ�����ɵĴ��ţ�ʮ�ֳ��ء���ʹ�Ǳ����ܺõ��ˣ�
����Ҳ������Ϊ������
LONG );
	set("exits", ([
		"north" : __DIR__"shidong",
		"south" : __DIR__"yandong",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50020);
	set("coor/y", -21050);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}