// /d/yixing/clzoulang1.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������������������ڱ����ܶ����լ�ˡ������Ǽ���ӻ�
�Ĳ񷿣����и�СС��ͤ�ӡ�һЩ�ճ������İ��ھ����ע����ÿ��
�ˡ�
LONG );
	set("exits", ([
		"west"  : __DIR__"clchaifang",
		"east"  : __DIR__"clbajiaoting",
		"south" : __DIR__"cldating",
		"north" : __DIR__"clzoulang2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yixing");
	setup();

	replace_program(ROOM);
}

