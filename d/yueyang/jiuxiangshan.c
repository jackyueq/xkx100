// Room: /d/yueyang/jiuxiangshan.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
��˵ɽ�������ƣ������ܳ��ɡ��볤�����ϵĺ������˵�󣬱���
��ʿ��͵���ɽ��ơ�����غ󣬱㱻����˷�����Ⱥ��ˣ������ֳ�һ
��Ц��������Ǻ���۴�ŭ����ն����˷������˷��ƣ����Լ����Ͷ�
�������ɾ��޳�����Ч����Ȼ�������ɾƣ��ɾƼ�Ȼ������˷��������
���������֮�䣬�޷���ʩ��
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"jiuxiangting",
		"west"  : __DIR__"yangyaozai",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/bai-shijing" : 1,
	]));
	set("coor/x", -1780);
	set("coor/y", 2290);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
