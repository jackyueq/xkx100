// /d/beihai/jingqing.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "����ի");
	set("long", @LONG
����֮����ի�������Ϊ����ի��Ϊһ����֮԰��԰������̫����
��ʱ֮����������Ϊ�ɳأ��ر�Ϊ�ã��ú���ɽ�أ����ҽԷ����Ҷ���
�����з�����ˮ�����ӻء������г������䣬����Ȫ�ȣ��Ⱥ���ɽʯ��
����ΪǬ¡ʱ��ʯ֮��Ʒ���鲼̫֮��ʯɽ����������͸���������ڴ�
��ľ�е�̨ͤ���Ż����ӳ����ɫ���š�
LONG
	);

	set("exits", ([
		"east"      : __DIR__"houmen",
		"southwest" : __DIR__"xitian",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -170);
	set("coor/y", 4100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
