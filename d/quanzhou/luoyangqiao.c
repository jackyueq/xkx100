// Room: /d/quanzhou/luoyangqiao.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������ϵ�һ���������µ���ʽʯ�š��ų�������Ŷ���ʮ
�����������������Է���������ʯ����ͷ�����ξ����ۿ���ʯʨ������
��ͤ��������׺��䣬��ʿʯ�񣬷������ˡ���֮��β����·ֲ���߰�
�ꡣ�ɴ��Űף�ˮ��ɽ�࣬ʤ״���˾�̾���ഫ����Ȫ��֪��������һ
�����ĵú�ð���º����ţ��ú������������������������ϵ�½·��ͨ
Ҫ�����󲿷����������Ļ�����ɴ˾�����
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"lingshan",
		"east" : __DIR__"tudimiao",
	]));
	set("coor/x", 1890);
	set("coor/y", -6580);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
