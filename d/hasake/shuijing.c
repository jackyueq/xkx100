// shuijing.c
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
ɽ���¹�ľ������һ�ۿ��������������ǵ�ˮԴ����̨����һ��ľ��
ר���ڿʵ����˺�ˮ��������һ������̤����ˮ����ˮ��������һֱ����
�˶��ߵ���ǡ�
LONG);
        set("resource/water", 1);
        set("exits", ([
                "eastup" : __DIR__"caochang",
                "southwest" : __DIR__"room-su",
                "northeast" : __DIR__"pmchang",                
        ]));
         set("objects", ([
                    __DIR__"obj/hamigua" : 2
        ]));
        setup();
}

void init()
{
        add_action("do_drink", "drink");
}
int do_drink(string arg)
{
        int current_water;
	int max_water;
        object me;
        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"ſ�ڿ������ľ�̨����ľ��Ҩ��һ��ˮ�ȡ�\n"
            , environment(me), ({me}) );
            write("�����һ�ھ��д���ɽ������������ѩˮ����ֱ���ۻ���\n");
        }
        else write("����Ҳ�Ȳ����ˡ�\n");
        return 1;
}