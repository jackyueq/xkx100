// Room: /d/guiyun/xiuxishi-m.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
        set("short", "���᷿");
        set("long", @LONG
�����ǹ���ׯ�е��ӵ���Ϣ�ң����ż���ľ�������Զ���һ֧�߽�
���ӣ��������������һ��С�������������䳡��
LONG );
	set("exits",([
		"east" : __DIR__"lianwuchang",
	]) );
	set("no_clean_up",0);
	set("no_fight", 1);
	set("sleep_room", 1);
	setup();
	replace_program(ROOM);
}
