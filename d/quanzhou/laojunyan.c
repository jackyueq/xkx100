// Room: /d/quanzhou/laojunyan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�Ͼ���");
	set("long", @LONG
����ɽ���߶��������ƣ���Χ�����������̲����𣬷羰���ˡ���
�е��̽����Ͼ�ʯ�񣬹ʳ��Ͼ��ҡ�����һ��Ȼ��ʯ�������ɡ�������
��ʯ���޴��˹�ߣ����ֺųơ��������µ�һ����ʯ��������ϥ������
ƾ��������ƽ�ӣ�˫�����磬����Ц�ݣ����׷ɶ���һ�����˴��飬��
�ֵ���̬�������ƣ��������Ͼ��ǣ��Ե�һ�ٶ�����
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"qianshouyan",
		"eastup"    : __DIR__"nantaiyan",
	]));
	set("coor/x", 1820);
	set("coor/y", -6380);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
