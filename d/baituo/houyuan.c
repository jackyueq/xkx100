// Room: /d/baituo/houyuan.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","��Ժ");
	set("long", @LONG
����Ƨ���ĺ�Ժ��ס�š�ŷ���ˡ��������衺���衻������������
�ߣ����Ѿ����ɻ��ˣ������ﾲ����
LONG	);
	set("exits",([
		"southeast" : __DIR__"zhuyuan",
	]));
	set("outdoors", "baituo");
	set("objects",([
		__DIR__"npc/zhangma" : 1,
	]));
	set("coor/x", -50020);
	set("coor/y", 20080);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

