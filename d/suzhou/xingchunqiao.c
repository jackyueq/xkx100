// Room: /d/suzhou/xingchunqiao.c
// Last Modified by Winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "�д���");
	set("long",@long
˳��ʯ�������߾��������д��ţ���վ���д��ŵ�ʯ���ϣ���ĿԶ
������ˮ���죬Ⱥɽ���ѣ���Ӱ��Ӱ����������
long);
	set("outdoors", "suzhou");
	set("exits",([
		"east" : __DIR__"shihu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 830);
	set("coor/y", -1080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
