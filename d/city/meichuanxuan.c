// Room: /yangzhou/meichuanxuan.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "÷����");
	set("long", @LONG
����������麣��������������ϣ���һ�����(lian)������������
��ƺ�ϣ��Զ���ʯ����Ƭ�̵أ�������ˮ�����ԡ�״������һˮ���⾳��
�����ıڣ������������������У�����������ۡ����Ķ��ϣ����ϻ���
�Σ�ɽʯ������׺��䡣���Ķ������Ժ�ʯ��ǽ��ɽ��ɽ��ʱ��ʱ����
���ƶ�������ʯ�ſɵǡ�
LONG );
	set("outdoors", "yangzhouw");

	set("no_fight", 1);
	set("exits", ([
		"south"     : __DIR__"chuanlang",
		"northeast" : __DIR__"hushishanzi",
	]));
	set("objects", ([
		__DIR__"npc/yangwanxiao" : 1,
	]));
	set("item_desc", ([
		"lian" : @LONG
                  ��         Լ
                  Ϊ         ��
                  ��         ��
                  ��         ��
                  ��         ÷
                  Ϊ         ��
                  ��         ��
LONG,
	]));
	set("coor/x", -11);
	set("coor/y", -48);
	set("coor/z", 0);
	set("no_quest",1);
	setup();
	replace_program(ROOM);
}