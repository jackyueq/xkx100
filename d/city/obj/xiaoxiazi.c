// xiaoxiazi.c
// δ�����ꡣ ��Ҫhave_married������
// ���ǵȽ�����ðɡ�

inherit ITEM;
inherit F_UNIQUE;

int opening();
int halt_opening();

void create()
{
    set_name( "Сϻ��", ({ "xiao xiazi", "xiazi", "box" }) );
    set_weight( 2000 );
    if ( clonep() )
        set_default_object( __FILE__ );
    else
    {
        set( "long", @LONG
���ϻ����С��ȴ���ֺܳ�����֪����ʲô�����Ƴɵġ�ϻ�ӱ����Ͽ���һЩ��
�صĻ��ƣ�����������͵ĺ�⣬����ȥ��Щ���졣
LONG
        );
        set( "unit", "��" );
        set( "value", 40 );
    }
    setup();
}

void init()
{
    add_action( "do_open_box", ({ "open", "kai" }) );
}

int do_open_box( string arg )
{
    object me = this_player();

    // �ƻ� : ����ǽ���һ�Ժ��������ϻ�ӣ��ܵõ������塣
    // û�н������򲻿���

    if ( !arg ) return 0;
    if ( !me->can_act() ) return 0;
    if ( !this_object()->id( arg ) ) return 0;

    if ( query ( "opened" ) ) return notify_fail( "���ϻ���Ѿ����ˡ�" );

    if ( !me->query( "have_married" ) )
        return notify_fail( "����ͼ�����ϻ�ӣ��������һ����ϻ�ӣ��о���һ�������������������ƿ���\n" );
    else
    {
        me->set_temp( "open_box_mark", 51 );
        if ( !query_temp ( "open_box" ) )
        {
            set_temp( "open_box", me->query( "have_married") );
        }
        {
            set_temp( "both_open", 1 ); 
        }
        me->start_busy( (:opening:), (:halt_opening:) );
        return 1;
    }
    return 0;
}

int opening()
{
    object ob, me = this_player();
    int mark = me->query_temp( "open_box_mark" );

    if ( mark > 50 )
    {
        message_vision( "$N���ְ���ϻ���ϡ�\n", me );
        write ( "��ͻȻ�е�ϻ������һ�����������������������ơ�\n" );
        me->add_temp( "open_box_mark", -10 );
        return 1;
    }

    if ( mark < 10 ) 
    {
        // ���ź��ˣ�ʱ����ˡ�
        message_vision( "ʱ�����", me );
        me->delete_temp( "open_box_mark" );
        remove_call_out( "del_temp" );
        call_out( "del_temp" , 1 );
        return 0;
    }

    me->add_temp( "open_box_mark", -10 );
    if ( !query_temp( "both_open" ) )
    {
        // ���Ű������ϻ�Ӱɡ�
        message_vision( "������", me );
        return 1;
    }
    // �ú��������ϻ���ˡ�
    else if ( query_temp( "open_box" ) != me->query( "have_married" ) 
        && query_temp( "open_box" ) != me)
    {
        // ����һ�Է��ޣ�ȴ��ͼ�����ϻ�ӣ�����ô�����أ�
        // һ��Ҫ���ͷ���grin
        message_vision( "", me );
        me->delete_temp( "open_box_mark" );
        remove_call_out( "del_temp" );
        call_out( "del_temp", 1 );
        return 0;
    }
    else
    {
        // ������������һ�Է����ڿ����ϻ���ˡ�:-)
        message_vision( "", me );
        // newһ˫�����壬������һ��һ����
        ob = new( __DIR__"huhua_ling" );
        ob->move(me);
        me->delete_temp( "open_box_mark" );
        remove_call_out( "del_temp" );
        call_out( "del_temp", 2 );
        return 0;
    }
    return 0;
}

int halt_opening()
{
    object me = this_player();
    write( "������������ϻ�ӵ���ͼ�ˡ�\n" );
    me->delete_temp( "open_box_mark" );
    remove_call_out( "del_temp" );
    call_out( "del_temp" , 1 );
    return 1;
}

void del_temp()
{
    if ( query_temp( "open_box" ) )
        delete_temp( "open_box" );
}

