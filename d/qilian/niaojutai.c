// Room: /d/qilian/niaojutai.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "���̨");
	set("long", @LONG
���Ŵ�ͨ�������ߣ���·���Լ��ѡ���;������������ʯ���ף���
�������޼������ˣ�ȴ�а���Ⱥ�ɣ�����ֻ����֮������ͷ���죬һ
Ƭ����֮�£������������ԲԴ�أ����ڽ��£��������������
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"eastdown" : __DIR__"datongling",
		"northup"  : __DIR__"mazongshan",
		"northwest": __DIR__"qilianshan",
	]));
	set("objects", ([
		"/d/hangzhou/npc/wuya"  : random(3),
		"/d/hangzhou/npc/maque" : random(3),
	]));
	set("coor/x", -11000);
	set("coor/y", 3000);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}