// Room: /d/chengdu/xijie1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ǳɶ�������֣��������������ַǷ��������������αȵĵ�
�̣�������ɫ�Ļ�������Ʈ��ɷ�����ޡ������İ���һ���ʮ�������
�ϼ�������̼�Ҳ��ʧʱ�����Ƴ�����ƽʱ�򲻵��Ķ������ϱ��Ǽ�ҩ
�̣��������Ǹ�ռ�������ӡ�
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"xijie2",
		"west"  : __DIR__"xijie",
		"north" : __DIR__"zhanbu",
		"south" : __DIR__"yaopu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8070);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

