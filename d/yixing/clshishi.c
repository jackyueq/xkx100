// /d/yixing/clshishi.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
�谵��ʯ��û�д��������ǳ��ְ�˽������ü����ҡ���Χ�ڷ�
�ż����̾ߣ�ǽ����Щ�¾ɲ�һ��Ѫ�ۣ����˲����������������ǳ�
ʪ��ͷ����ʱ����ˮ�顣
LONG );
	set("exits", ([
		"west" : __DIR__"clyongdao",
	]));
	set("objects",([
		__DIR__"npc/cl_zhan" : 1,
	]));
	set("no_clean_up", 0);
	setup();

	replace_program(ROOM);
}
