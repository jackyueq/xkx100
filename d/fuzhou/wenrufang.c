// Room: /d/fuzhou/wenrufang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "���巻");
	set("long", @LONG
����ɽ����������ַ������δ�����֣�¾��ڴˣ���Ϊ���巻��
��Ϊ�������֣��֮�⣬���Ⱥ�ס�о����ᶽ��̨���ܱ��ʹ���������
��������ʡ�����ž���������ʵ���ʦ�±��֮���³��ã�������ͨ־
��������ܵ�������ʿ���ʳ����ַ�������ʵ�� 
LONG );
	set("exits", ([
		"east"    : __DIR__"nanhoujie3",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1833);
	set("coor/y", -6330);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
