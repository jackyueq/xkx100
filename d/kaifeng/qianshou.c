// /kaifeng/qianshou.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "ǧ��ǧ�۷��");
	set("long", @LONG
��������й������ǧ��ǧ�۹�������˵���������ն�����������
��ǧ������ϸ��ȥ��ֻ��������������̶̵��ֱ�ÿ���������Ķ���ֻ
�۾�����˼�Ǿ����㡰���۾��࣬ʲô���ܹ�ע�⵽�����ֶ࣬ʲô��
�ܹܵ����ɱ������¡���
LONG
	);
	set("exits", ([
		"west" : __DIR__"fangsheng",
		"east" : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/oldwomen" : 1,
		__DIR__"npc/obj/guanyin" : 1,
	]));

	setup();
	replace_program(ROOM);
}
