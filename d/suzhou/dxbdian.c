// Room: /d/suzhou/dxbaodian.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "���۱���");
	set("long",@long
�����������µĴ��۱�����й������������������Ҹ������⡢
����������һȺ����С���������ڷ���ǰ�ĵ����о���������������
������һ�����ӷ����黨ǳЦ�����ݣ����˶�ʱ���𼸷�����֮�С�
��߾�����һ�Ӷ�ɮ�������룬�������ֳֽ䵶���ƺ���Ѳ�µ�ɮ�ˡ�
long);
	set("exits",([
		"out"   : __DIR__"lingyansi",
		"north" : __DIR__"cangjingge",
	]));
	set("no_clean_up", 0);
	set("coor/x", 900);
	set("coor/y", -1130);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
