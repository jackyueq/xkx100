// d/qingcheng/chufang.c
//
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ɽ�ĳ�������ʰ���쳣�ɾ���������Ŵ�Բ�������ϰ���
һЩ���ĺͲ�ˮ����Χ����ż������Ρ����ڻ����ż���ɽҰ�ʻ���ƽ
ʱ���ɽ�ĵ��ӺͼҾ춼�������ò͡�
LONG );
	set("exits",([
		"south" :__DIR__"zoulang3",
	]));
	set("objects",([
		__DIR__"obj/laitangyuan" : random(3)+1,
		__DIR__"obj/kudingcha" : random(2)+1,
	]));

	set("no_clean_up", 0);
	set("coor/x", -8090);
	set("coor/y", -830);
	set("coor/z", 90);
	setup();
	replace_program(ROOM) ;
}