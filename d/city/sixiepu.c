// Room: /yangzhou/sixiepu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","���˿Ь��");
	set("long",@LONG
�������˿Ь���ԡ����ʺϽţ�����ʹ��������ơ����ڳ�����һ
˫�ش���İ�˿Ь������ֻ�о�����Ŵ����¡���̨�Ϸ��ż�˫˿Ь��
���ϵ�Ь���Ϸ���Ƥѥ����ѥ�ȸ�ʽЬ�����ɹ������Դ����Ա���ѡ��
�Լ�ϲ���ĺ��ʵ�Ь��
LONG );
	set("exits", ([
		"south" : __DIR__"caiyidongjie",
	]));
	set("objects", ([
		__DIR__"npc/libailv" : 1,
	]));
	set("coor/x", 60);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}