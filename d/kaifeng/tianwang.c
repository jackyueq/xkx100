// /kaifeng/tianwang.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������Ĵ��������շ������߾��ڷ�̳֮�ϣ������к�ɫդ
�����м��ͨ��������ÿ���������ǰ����һ�����Ź�������Ů��Ĥ�ݣ�
��������˳��
LONG);
	set("objects", ([
		__DIR__"npc/hufa" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"qianyuan",
		"north" : __DIR__"zhongyuan",
	]));

	setup();
	replace_program(ROOM);
}
