// Room: /d/yanping/baoyunsi.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������λ�ھŷ�ɽ�ϣ�ʼ�����Ƴ�����Ԫ�꣬ԭ���Ϸ��ռ�Ժ��Ԫ
���ĳơ����¡������С�������������������ΰ��������̻Իͣ�
���Թ�ľ���죬Ϧ���𴦣��������֡�
LONG );
	set("exits", ([
		"northdown" : __DIR__"9fengshan",
	]));
	set("objects", ([
		"/d/hangzhou/npc/seng" : 1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1480);
	set("coor/y", -6230);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
