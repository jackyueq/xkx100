// yaojishi.c ҩ����
// Winder Oct.10 1998

inherit ROOM;
int do_pullout(string arg);

void create()
{
        set("short", "ҩ����");
        set("long", @LONG
������ȫ�����ҩ����ҩ�ĵط�����䷿�䱾���ܴ�ֻ��
��ǰ�����Ҷѷŵ�ҩ��ҩ�伷���Ե�С���ˡ�ҩ���Ѿ��ܳ¾��ˣ�
���������Ϻõ��Ϻ�����ľ���ɵģ���˵������ľ�����ɵĹ���
�������ض��������������ҩ�������и�����(drawer)��
LONG
        );
        set("sleep_room",1);
        set("exits", ([
                "east" : __DIR__"xianzhentang",
        ]));

        set("objects", ([
                CLASS_D("quanzhen")+"/zhangyao" : 1,
        ]));

        set("item_desc", ([
        "drawer": "һ�����룬��֪������Ϊ���Ļ���ʲôԭ��û��������\n"
        ]) );

        set("count",1);
	set("coor/x", -2810);
	set("coor/y", 100);
	set("coor/z", 170);
	setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_pullout","pullout");
}

int do_pullout(string arg)
{
        object me=this_player();
        object ob;

        if( !arg || arg != "drawer" ) {
                return notify_fail("��Ҫ����ʲô��\n");
        }

        if (query("count")>0) {
        message_vision("$N������ҩ����ת����ȥ���ɿ�ذѳ������������������ʲô������\n",this_player());
        message_vision("��û���ü�������ҩ������ת��������ֻ�ŵ�$Nһ��ץ�������Ķ���\n", this_player());
        message_vision("�������Ȼ��װ��̧ͷ��ҩ���ľ�ʣ�����һ���������µ����ӡ���\n",this_player());
        message_vision("������ҩ������Ȼû������$N������һ���������޹��ı������˻�����\n",this_player());
        add("count",-1);
        ob=new("/clone/medicine/vegetable/tianqi");
        ob->move(me);
        }
        else {
        message_vision("$N������ҩ����ת����ȥ���ɿ�ذѳ�������������տ���Ҳ��ԭ����\n",this_player());
        message_vision("����Ķ��������Ѿ�����ȡ���ˡ�\n", this_player());
        }

        return 1;
}