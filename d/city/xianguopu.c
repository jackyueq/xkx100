// Room: /yangzhou/xianguopu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","����ʹ���");
	set("long",@LONG
��˵�����һ�����ݳǵ����ֺţ����ݳ��ڵĴ��˼Ҳ����ʹ���
�����ˣ��������������������Ϊ���֣�С��æ��æȥ�к�����ҡ���
�����һ�̽��Ҷ���ϵĸ�ɫ�ʹ�Ʈ��������������Ƣ�����˴�����
�Ρ����ϵ��������и����ӣ��ƺ����ʷ�������
LONG );
	set("exits", ([
		"west" : __DIR__"caiyidongjie",
	]));
	set("objects", ([
		__DIR__"npc/pengbaoxian" : 1,
	]));
	set("coor/x", 70);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}