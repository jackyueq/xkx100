// Room: /yangzhou/tangwu1.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��֮�ϱ���һ�񻨴������ȣ�������ɽǽ���д�鴰�����������
���б��ϱ���һ������÷׮���ã������پ���ī���ɶ������ҹ�һ���
(lian)����ǽ��һ�׺�ľ�������ϳ¹�ƿ���辰����ǰһ��÷�񻨷�����
����һ�Ժ�÷��̫ʦ�Ρ�����齣����һ�ܹ��飬�������ҡ�
LONG );

	set("item_desc", ([
		"lian" : @LONG
                  ������          ������ 
                  ���Щ�          ���ǩ�
                  ������          ��¥��
                  ��Ǳ��          ���婦
                  ������          ������
                  ����          ���Щ�
                  ���Ω�          ������
                  ���Щ�          ��Զ��
                  ������          ������
LONG,
	]));
	set("exits", ([
		"south" : __DIR__"rongxiyuan",
	]));
	set("objects", ([
		__DIR__"npc/qiuhaoshi" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", -39);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}