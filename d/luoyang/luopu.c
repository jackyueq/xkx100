// Room: /d/luoyang/luopu.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "�������");
	set("long",  @LONG
��ӣ�����а����������񣬳����Բ���һ���ļ��羰�续������
�ǡ�������ġ������º��ʱ�ڣ�����ʫ�黭�⡣����ʱ�����ӽ�˵
���ں�������һλ��Ů�����ͽ��ⷢ��д��һƪ�����񸳡����ųơ���
���Ľܡ������������¬���ڡ���������ǻ������������ȥ���Ƹ�
��ʱ���Ϲ���ѭ�źӵ̣�����ӽʫ�������ɫ֮�ѣ����������
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"      : __DIR__"southgate",
		"southeast" : __DIR__"dukou1",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -490);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
