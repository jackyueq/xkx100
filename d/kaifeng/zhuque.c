// /kaifeng/zhuque.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "��ȸ��");
	set("long", @LONG
�����ڳǵĳ��ţ��ߴ�ĳ�ǽ�ô���ש�ֺ���֭���ɣ�ʱ��ĳ�ˢ
ʹ��ǽש��Ϊ����ɫ�����������ǽ�¥�����治Զ�����Ǵ�����µİ�
�������
LONG);
	set("exits", ([
		"south" : __DIR__"road1",
		"north" : __DIR__"road2",
		"westup" : __DIR__"jiaolou1",
		"eastup" : __DIR__"jiaolou2",
	]));
	set("objects", ([
		__DIR__"npc/guanbing" : 2,
		__DIR__"npc/walker" : 1,
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
