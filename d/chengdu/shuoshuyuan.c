// Room: /d/chengdu/shuoshuyuan.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "˵��Ժ");
	set("long", @LONG
����������ȫ�������������ű������ݣ���Ȼ������¡���ű���
һ�������������ӡ���������������ʦ���洫���󲿷�ʱ�䶼������
˵�顣�����������ף��Ժ��ζ�������Ϊ���ѱ����ʦ�š�С�������
������������������ί����������Ϊ�������񡱡�
LONG	);
	set("exits", ([
		"east" : __DIR__"shuchang",
	]));
	set("objects", ([
		__DIR__"npc/wangcheng" : 1,
		__DIR__"npc/shenjinyin" : 1,
	]));
	set("coor/x", -8070);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

