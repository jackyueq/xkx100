// Room: /yangzhou/daxiongbaodian.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","���۱���");
	set("long",@LONG
����������麣�ӭ������ܵ��ݼ��ϣ����С����۱�����ֺ��ҡ�
�ݼ�����Ƕ����һ�棬ӭ��Ƕ�������˳�����֣�����Ƕ����̩�񰲡�
���֡�
    ���۱������������Ϊ����Ĳ��𣬶�Ϊҩʦ���������
Ϊ�������簢���ӷ�����Ĳ�������в��������������ӣ��������ѣ�
������Ҷ����������Ϊʮ���޺�����������������档��̳����Ϊ����
Ⱥ�񺣵������й��������ŲȾ������񣬹��������оȰ��ѵ����񡣹�
�����������Ʋ�ͯ�Ӻ���Ů�����������д�С�����������
LONG );
	set("exits", ([
		"east"  : __DIR__"qingkongge",
		"west"  : __DIR__"gulintang",
		"north" : __DIR__"cangjinglou",
		"south" : __DIR__"yongdao",
	]));
	set("objects", ([
		"/d/hangzhou/npc/seng" : 1,
	]));
	set("coor/x", -30);
	set("coor/y", 170);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}