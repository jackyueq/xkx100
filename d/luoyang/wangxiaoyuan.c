//  Room:  /d/luoyang/wangxiaoyuan.c

inherit  ROOM;

void  create  ()
{
	set("short",  "СͥԺ");
	set("long",  @LONG
�������š��ľ����˳ɶ��㣬��԰��ɫ��Ⱥ�����Ľ��ţ�����һ��
ʮ�����ɵ�С԰��԰��СС�ĳ����У�ǳǳ��ˮ�����һЩϸϸ����
�㣬Ҳ�����ų�����ʢ�ŵ�ĵ����
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"   :  __DIR__"wangdayuan",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/obj/yaohuang" : random(2)+1,
		__DIR__"npc/obj/weizi" : random(2)+1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -610);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}