// Room: /d/guiyun/xiuxishi-f.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
        set("short", "Ů�᷿");
        set("long", @LONG
�����ǹ���ׯŮ���ӵ���Ϣ�ң����ż���ľ�������Զ���һ֧�߽�
���ӣ�����������ݽ�һ�ż��ʣ�����һ��������ɢ�ŵ������㡣
LONG );
	set("exits",([
		"west" : __DIR__"lianwuchang",
	]) );
	set("no_clean_up",0);
	set("no_fight", 1);
	set("sleep_room", 1);
	setup();
	replace_program(ROOM);
}
