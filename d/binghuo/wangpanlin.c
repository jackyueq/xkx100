// Room: /binghuo/wangpanlin.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ɽ�Ǹ�С����ɽʯ��ľ���޿ɹ�֮�������Ͻ��и����壬Φ
�ɸ��ʣ�ͣ����ʮ���Ҵ󴬣����Ǿ޾����ɳ��һ���˵���������
�������������ڱȽ����������������ԭ�����˲�����ϰ����������
����涷��
LONG );
	set("no_sleep_room",1);
	set("outdoors", "wangpan");
	set("exits", ([
		"southeast" : __DIR__"wangpangang",
		"southwest" : __DIR__"wangpangu2",
		"west"      : __DIR__"wangpanshan",
	]));
	set("objects", ([
		__DIR__"npc/gao" : 1,
		__DIR__"npc/jiang" : 1,
	]));
	setup();
	replace_program(ROOM);
}

