// liangong.c ������
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ʯ����״�������أ�ǰխ�����Ϊ���Σ����߰�Բ������ȴ
��������״��ԭ��������ǰ������ʦ�������ң�ǰխ���ƣ����ʹȭ��
��Բ�н������Ƿ��ڡ�
LONG	);
	set("exits", ([
		"northeast" : __DIR__"mudao03",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("coor/x", -3240);
	set("coor/y", -10);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
