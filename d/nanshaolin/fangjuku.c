// Room: /d/nanshaolin/fangjuku.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "���߿�");
	set("long", @LONG
����һ��ܴ�ķ��䣬��ǽ����ط���һ��������ӣ����ٹ�����
�����ţ�¶������ĸ��ַ��ߣ�Ʒ��֮�࣬������ƽ������һλ����ɮ
������ͷ����һ������Ļ��ߡ��������Ҳû��ע�⡣
LONG );
	set("exits", ([
		"north" : __DIR__"lshuyuan",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangtu" : 1,
	]));
	set("coor/x", 1790);
	set("coor/y", -6210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


