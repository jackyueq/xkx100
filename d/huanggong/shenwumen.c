// Room: /d/huanggong/shenwumen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
ԭ��������. �����ǻʳǵı���, �ʰ����εĽ���, �����źϳ���
��, �Ƿ����ͱ����ʳǵĹ���. ��¥�����е, �����ӹ�, �ƻ�ʱ��
�Ӱ������, ����������ı�ʱ, ֱ�����շ�������. ÿ����ѡ��Ů, 
ӦѡŮ�ӽԴӴ����빬. ��ĩ���Գɹ���������ʱ, �������ɴ�������
úɽ, ��������. 
LONG 	);
	set("outdoors", "huanggong");
	set("no_fight", "1");
	set("exits", ([ /* sizeof() == 2 */
		"east"  : __DIR__"dao5",
		"west"  : __DIR__"dao6",
		"north" : __DIR__"jingshan",
		"south" : __DIR__"qinandian",
	]));
	set("objects", ([
		__DIR__"npc/yulin" : 2,
		__DIR__"npc/chaerzhu" : 1,
	]));

	set("coor/x", -200);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir!="north")
		return notify_fail("�������ǰ��ס�㣬����˵������λ"+RANK_D->query_respect(me)+"���빬��ǰ�š�\n");
	return ::valid_leave(me, dir);
}