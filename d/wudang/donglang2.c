// Room: donglang2.c ��������
inherit RESTROOM_OUT;

void create()
{
    set("short", "��������");
    set("long", @LONG
������һ�������ϣ���Լ�����������ߴ������������ƺ���������
����������������һ���� (men)�������������š��ϱ��Ǽ��������͵�
���ӣ�ʮ�ֵ����ţ�����Ʈ��һ����Ĳ��㣬��������ϸ��ز�֪˵��
Щʲô������Ů���ӡ��Գԡ�Ц��������
LONG );

    set("exits", ([
        "east" : __DIR__"liangongfang",
        "south" : __DIR__"chashi",
        "west" : __DIR__"donglang1",
    ]));
  set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -920);
	set("coor/z", 90);
	set("door_name","��");
	set("door_dir","north");
	set("restroom",__DIR__"xiuxishi");
	set("open_door_msg","���Ϲ��˸����ӣ��Ͽ��δ���\n");
	set("inside_msg",   "���Ϲ��˸����ӣ��������\n");
	set("no_one_msg",   "���Ϲ��˸����ӣ���Ϣ�ҡ�\n");
	set("item_desc/door",(: look_men : ));
	set("item_desc/men", (: look_men : ));
	setup();
}
