// Room: /d/quanzhou/nantaiyan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��̨��");
	set("long", @LONG
������ǧ���Ϳ��项��������Դɽ����ߴ���һƬ���ʵľ�ʯ��Ȼ
������ǰ���������ͱڣ�����ʮ���վ�����ʯ���Կ��š�����̨����
���֡���̨���С����Ǹ󡹣���Ϊɽ�Ƹߣ����ﳣ����������Ϊ�ƺ���
��ɽ�����ӣ����ڿ��С�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown" : __DIR__"qingyuandong",
		"westdown" : __DIR__"laojunyan",
	]));
	set("coor/x", 1830);
	set("coor/y", -6380);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
