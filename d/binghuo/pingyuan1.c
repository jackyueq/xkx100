// Room: /binghuo/pingyuan1.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ƽԭ");
	set("long", @LONG
������ʮ���﷽Բ��ƽԭ���˴����д�Ƭ���ؿɹ����ۣ�ʵ��˵
�����Ŀ���;���������˵������֮�⣬��������滨���ݴ�֮
�У�ż������һЩ�в�����Ŀ�Ĵ���С�ޣ�����Ҳ���޺����ˡ���
ת��һ��Ƭ���֣�ֻ�����������ƺ���һ��ʯɽ��
LONG );
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"haitan",
		"north"  : __DIR__"shulin3",
	]));
	setup();
	replace_program(ROOM);
}

