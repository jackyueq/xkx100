// Room: /binghuo/zhou.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
��ɴ������ӳ�£�һλ�������˶�����ͷ���ְ�ʤѩ�����΢�ݣ�
ü���ͦ��һЦʱ�����ǳǳһ�����С�ֻ�����������䣬�Ǹ���Ů
���ڸ��١�
LONG );
	set("outdoors", "binghuo");
	set("exits", ([
		"out" : __DIR__"qiantang",
	]));
	set("objects", ([
		"/d/mingjiao/npc/yinsusu" : 1,
	]));
	setup();
}
