// Room: /d/wuxi/road1.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ���������ݺ������Ĵ���������ĵ�����֮��Ҳʹ�ùٸ�
������ʮ�ֵ���ʵ��������·��Ȼ����û�Ǯ�ˡ������·Ҫ�ȱ��
�ط������ö࣬·�ߵ�������Ҳ�Ե��ر�þ����������Կ�������
�������š�������һƬïʢ�������֣�������һ��С������ȥ����
�Ϳ���ȥ�����ˡ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"road2",
		"west"  : __DIR__"eastgate",
	]));
	set("coor/x", 500);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}