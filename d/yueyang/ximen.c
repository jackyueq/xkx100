// Room: /d/yueyang/ximen.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������������¥�����ţ�����Ҳû�йٱ����أ����������ؤ���
���£��������ǵ��ΰ�Ҳ��ʵ���ϸ�ؤ��ӹ��ˡ��ٸ�Ҳ����������
��εģ�����ֻҪؤ���������Ҳ·��ʰ�š�ҹ���ջ��ġ�
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"east"     : __DIR__"xijie",
		"northup"  : __DIR__"loumen",
		"westdown" : __DIR__"shijie7",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/xiang" : 1,
	]));
	set("coor/x", -1430);
	set("coor/y", -2270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
