// Room: /d/suzhou/shuiwa1.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
        set("short", "������");
        set("long",@long
������Ϊ������¥�����׳ơ������롱���ഫ��ʩ�ڴ������ۡ���
����һ��ֱ̫ͨ�����˹������СϪ��
long);
	set("outdoors", "suzhou");
	set("exits",([
		"eastup"    : __DIR__"shiyuan",
		"southeast" : __DIR__"caixiangjing",
	]));
	set("no_clean_up", 0);
	set("coor/x", 870);
	set("coor/y", -1110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
