// Room: /qingcheng/jianfugong.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
�������ɳ����˹ۣ������������˷��¹�Ҳ���ഫ����������
�����޵��ڴˡ�Ժ����ľ��ɽ���໥��ӳ����Χ��ľ�Դ䣬Ũ���
�գ��������ˣ�ʮ����ˬ������Ҳ����ɽ����㡣
LONG );
	set("exits", ([
		"south"     : __DIR__"xiaoqiao",
		"northwest" : __DIR__"path1",
	]));
	set("objects", ([
		__DIR__"npc/ji" : 1,
		__DIR__"npc/shen" : 1,
		"/clone/misc/dache" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -8060);
	set("coor/y", -920);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
