// /d/shenlong/shulin1 ����
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	int i;
	set("short", "����");
	set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï
�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ���������
�����е�����ʹ�˲�����ԥ��ǰ���ĽŲ���
LONG
	);
	i = random (3);
	switch (i)
	{
		case 0:
			set("objects", ([
				"/d/city/obj/shuzhi" : 1,
				"/d/jiaxing/npc/wuya" : 1,
			]));
			break;
		case 1:
			set("objects", ([
				"/d/city/obj/shuzhi" : 1,
				"/d/wudang/npc/yetu" : 1,
			]));
			break;
		case 2:
			set("objects", ([
				"/d/city/obj/shuzhi" : 1,
				"/d/shenlong/npc/snake" : 1,
			]));
			break;
	}
	set("exits", ([
		"west"    : __DIR__"tiandi2",
		"north"   : __DIR__"shulin2",
		"southup" : __DIR__"shangang",
	]));
	set("outdoors", "shenlong");

	setup();
	replace_program(ROOM);
}

