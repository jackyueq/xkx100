// Room: /d/yanping/mingcuige.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ʼ�������Σ���Ϊ�������念����ʮһ���������ĳ�����
�����ʸ��ڷ��ʯ�����Ҿ����ϣ����ƿ���¥���������ơ��β��
���ľ������Ⱥ�����������أ��������ġ�������Զ�ۣ�����һ���ڿ�
�����������������Ρ���ɽ���Ϻ���ε����ľ�С���ʫ�ƣ���������
���У�����������������ڻ������̣�����컡����ʫ�������ʫ��
�̣�������˷����뻭��������Ҷ���ź졣��
LONG );
	set("exits", ([
		"down" : __DIR__"fengguanyan",
	]));
	set("objects", ([
		"/d/hangzhou/npc/shami" : 1,
	]));
	set("outdoors", "yanping");
	setup();
	replace_program(ROOM);
}
