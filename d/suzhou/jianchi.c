// Room: /d/suzhou/jianchi.c
// Last Modified by Winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����λ��ǧ��ʯ�����ϣ�������������һ��ƽ��֮������ˮ���겻
�ɿݡ�����Ĺ���������ã�����֮���������ʽ��Ρ�����ʯ���Ͽ�
�����𽣳ء��ĸ����֡����ؾ��������������֮���ԣ��±���������
�ܴ��ң���ڿ̴�׭�����ء����֡�
LONG);
	set("outdoors", "suzhou");
	set("exits",([
		"northeast" : __DIR__"qianrenshi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 790);
	set("coor/y", -1030);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
