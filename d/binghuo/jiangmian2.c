// Room: /binghuo/jiangmian2.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "Ǯ������");
	set("long", @LONG
��������Խ����ʻ�������ʱ��֮����ӿ�ĳ�ˮ���˳�����˳
��˳ˮ�����и�Զ��ԶԶ����Ǯ�����ڵĶ���֮�У��и�����С����
ɽʯ��ᾣ������˾ӡ��Ǿ�������ɽ����
LONG );
	set("no_sleep_room",1);
	set("outdoors", "wangpan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

