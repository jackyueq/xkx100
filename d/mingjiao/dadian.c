//room: /d/mingjiao/dadian.c
inherit ROOM;

void init();

void create()
{
	set("short","���̴��");
	set("long", @LONG
�߽����ͻ��һ������֮�⣬�����ʮ�ֿտ����������յ��
�ƣ������Ǿ�׳�彣��ʿ����ɭ�ϱ��ˡ�������һ������ǰ��һ��̴
ľ������ͷ������ʥ����(ling)��ö������������һ����������������
��������ʥ��ͼ������ֱ�����¡������϶���һ�ˣ��Ų��¶��Ը߹�
��Ц��ŭ���������������̽������޼ɡ�
LONG );
	set("exits",([
	    "south" : __DIR__"qiandian",
	    "enter" : __DIR__"neishi",
	]));
	set_temp("tieling",8);
	set("objects",([
		CLASS_D("mingjiao")+"/zhangwuji":1,
		CLASS_D("mingjiao")+"/yangxiao":1,
		CLASS_D("mingjiao")+"/fanyao":1,
		CLASS_D("mingjiao")+"/yintianzheng":1,
		CLASS_D("mingjiao")+"/xiexun1":1,
		CLASS_D("mingjiao")+"/weiyixiao":1,
	]));
	set("coor/x", -52030);
	set("coor/y", 1070);
	set("coor/z", 110);
	setup();
}